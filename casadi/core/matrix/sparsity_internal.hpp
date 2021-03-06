/*
 *    This file is part of CasADi.
 *
 *    CasADi -- A symbolic framework for dynamic optimization.
 *    Copyright (C) 2010-2014 Joel Andersson, Joris Gillis, Moritz Diehl,
 *                            K.U. Leuven. All rights reserved.
 *    Copyright (C) 2011-2014 Greg Horn
 *
 *    CasADi is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    CasADi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with CasADi; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


#ifndef CASADI_SPARSITY_INTERNAL_HPP
#define CASADI_SPARSITY_INTERNAL_HPP

#include "sparsity.hpp"
/// \cond INTERNAL

namespace casadi {

  class CASADI_EXPORT SparsityInternal : public SharedObjectNode {
  private:
    /* \brief Sparsity pattern in compressed column storage (CCS) format
       The first two entries are the number of rows (nrow) and columns (ncol).
       The next (ncol+1) entries are the column offsets (colind). This means that
       the number of nonzeros (nnz) is given as sp_[sp_[1]+2].
       The last nnz entries are the rows of the nonzeros (row). See public class
       for more info about the CCS format used in CasADi. */
    std::vector<int> sp_;

  public:
    /// Construct a sparsity pattern from arrays
    SparsityInternal(int nrow, int ncol, const int* colind, const int* row) :
      sp_(2 + ncol+1 + colind[ncol]) {
      sp_[0] = nrow;
      sp_[1] = ncol;
      std::copy(colind, colind+ncol+1, sp_.begin()+2);
      std::copy(row, row+colind[ncol], sp_.begin()+2+ncol+1);
      sanityCheck(false);
    }

    /** \brief Get number of rows (see public class) */
    inline const std::vector<int>& sp() const { return sp_;}

    /** \brief Get number of rows (see public class) */
    inline int size1() const { return sp_[0];}

    /** \brief Get number of columns (see public class) */
    inline int size2() const { return sp_[1];}

    /** \brief Get column offsets (see public class) */
    inline const int* colind() const { return &sp_.front()+2;}

    /** \brief Get row indices (see public class) */
    inline const int* row() const { return colind()+size2()+1;}

    /// Number of structural non-zeros
    inline int nnz() const { return colind()[size2()];}

    /// Check if the dimensions and colind, row vectors are compatible
    void sanityCheck(bool complete=false) const;

    /** \brief Get the diagonal of the matrix/create a diagonal matrix
     *
     * \param[out] mapping will contain the nonzero mapping
     */
    Sparsity getDiag(std::vector<int>& mapping) const;

    /// Calculate the elimination tree: See cs_etree in CSparse
    std::vector<int> eliminationTree(bool ata) const;

    /// Find strongly connected components: See cs_dfs in CSparse
    int depthFirstSearch(int j, int top, std::vector<int>& xi, std::vector<int>& pstack,
                         const std::vector<int>& pinv, std::vector<bool>& marked) const;

    /// Find the strongly connected components of a square matrix: See cs_scc in CSparse
    int stronglyConnectedComponents(std::vector<int>& p, std::vector<int>& r) const;

    /// Transpose the matrix
    Sparsity T() const;

    /** \brief Transpose the matrix and get the reordering of the non-zero entries,
     *
     * \param[out] mapping the non-zeros of the original matrix for each non-zero of the new matrix
     */
    Sparsity transpose(std::vector<int>& mapping, bool invert_mapping=false) const;

    /// Check if the sparsity is the transpose of another
    bool isTranspose(const SparsityInternal& y) const;

    /// Check if the sparsity is a reshape of another
    bool isReshape(const SparsityInternal& y) const;

    /// Breadth-first search for coarse decomposition: see cs_bfs in CSparse
    void breadthFirstSearch(int n, std::vector<int>& wi, std::vector<int>& wj,
                            std::vector<int>& queue, const std::vector<int>& imatch,
                            const std::vector<int>& jmatch, int mark) const;

    /// Collect matched cols and rows into p and q: see cs_matched in CSparse
    static void matched(int n, const std::vector<int>& wj, const std::vector<int>& imatch,
                        std::vector<int>& p, std::vector<int>& q, std::vector<int>& cc,
                        std::vector<int>& rr, int set, int mark);

    /// Collect unmatched cols into the permutation vector p : see cs_unmatched in CSparse
    static void unmatched(int m, const std::vector<int>& wi, std::vector<int>& p,
                          std::vector<int>& rr, int set);

    /// return 1 if col i is in R2 : see cs_rprune in CSparse
    static int rprune(int i, int j, double aij, void *other);

    /** \brief drop entries for which fkeep(A(i, j)) is false; return nz if OK, else -1: :
     * see cs_fkeep in CSparse
     */
    static int drop(int (*fkeep)(int, int, double, void *), void *other,
                    int nrow, int ncol,
                    std::vector<int>& colind, std::vector<int>& row);

    /// Compute the Dulmage-Mendelsohn decomposition : see cs_dmperm in CSparse
    int dulmageMendelsohn(std::vector<int>& rowperm, std::vector<int>& colperm,
                          std::vector<int>& rowblock, std::vector<int>& colblock,
                          std::vector<int>& coarse_rowblock, std::vector<int>& coarse_colblock,
                          int seed) const {
      return T()->dulmageMendelsohnUpper(colperm, rowperm, colblock, rowblock,
                                                 coarse_colblock, coarse_rowblock, seed);
    }

    /** \brief Compute the Dulmage-Mendelsohn decomposition
     *
     * -- upper triangular TODO: refactor and merge with the above
     */
    int dulmageMendelsohnUpper(std::vector<int>& rowperm, std::vector<int>& colperm,
                               std::vector<int>& rowblock, std::vector<int>& colblock,
                               std::vector<int>& coarse_rowblock,
                               std::vector<int>& coarse_colblock, int seed) const;

    /// Compute the maximum transversal (maximum matching): see cs_maxtrans in CSparse
    void maxTransversal(std::vector<int>& imatch,
                        std::vector<int>& jmatch, Sparsity& trans, int seed) const;

    /// Find an augmenting path: see cs_augment in CSparse
    void augmentingPath(int k, std::vector<int>& jmatch,
                        int *cheap, std::vector<int>& w, int *js, int *is, int *ps) const;

    /**
     * return a random permutation vector, the identity perm, or p = n-1:-1:0.
     * seed = -1 means p = n-1:-1:0.  seed = 0 means p = identity.
     * otherwise p = random permutation. See cs_randperm in CSparse
     */
    static std::vector<int> randomPermutation(int n, int seed);

    /// Invert a permutation matrix: see cs_pinv in CSparse
    static std::vector<int> invertPermutation(const std::vector<int>& p);

    /// C = A(p, q) where p and q are permutations of 0..m-1 and 0..n-1.: see cs_permute in CSparse
    Sparsity permute(const std::vector<int>& pinv, const std::vector<int>& q, int values) const;

    /// C = A(p, q) where p and q are permutations of 0..m-1 and 0..n-1.: see cs_permute in CSparse
    void permute(const std::vector<int>& pinv,
                 const std::vector<int>& q, int values,
                 std::vector<int>& colind_C,
                 std::vector<int>& row_C) const;

    /// consider A(i, j), node j in ith col subtree and return lca(jprev, j): See cs_leaf in CSparse
    static int leaf(int i, int j, const int *first, int *maxfirst,
                     int *prevleaf, int *ancestor, int *jleaf);

    /** compute nnz(V) = S->lnz, S->pinv, S->leftmost, S->m2 from A and S->parent:
     * See cs_vcount in CSparse
     */
    int vcount(std::vector<int>& pinv, std::vector<int>& parent, std::vector<int>& leftmost,
               int& S_m2, double& S_lnz) const;

    /// post order a forest: See cs_post in CSparse
    static std::vector<int> postorder(const std::vector<int>& parent, int n);

    /// Depth-first search and postorder of a tree rooted at node j: See cs_tdfs in CSparse
    static int depthFirstSearchAndPostorder(int j, int k, int *head,
                                            const int *next, int *post, int *stack);

    /// row counts of LL'=A or LL'=A'A, given parent & post ordering: see init_ata in CSparse
    void init_ata(const int *post, int *w, int **head, int **next) const;

    /// Row counts: See cs_counts in CSparse
    std::vector<int> counts(const int *parent, const int *post, int ata) const;

    /** Approximate minimal degree, p = amd(A+A') if symmetric is true, or amd(A'A) otherwise.
     * order 0:natural, 1:Chol, 2:LU, 3:QR. See cs_amd in CSparse
     */
    std::vector<int> approximateMinimumDegree(int order) const;

    /// symbolic ordering and analysis for QR or LU: See cs_sqr in CSparse
    void prefactorize(int order, int qr, std::vector<int>& pinv, std::vector<int>& q,
                      std::vector<int>& parent, std::vector<int>& cp, std::vector<int>& leftmost,
                      int& m2, double& lnz, double& unz) const;

    /// clear w: cs_wclear in CSparse
    static int wclear(int mark, int lemax, int *w, int n);

    /// keep off-diagonal entries; drop diagonal entries: See cs_diag in CSparse
    static int diag(int i, int j, double aij, void *other);

    /// C = A*B: See cs_multiply in CSparse
    Sparsity multiply(const Sparsity& B) const;

    /** x = x + beta * A(:, j), where x is a dense vector and A(:, j) is sparse:
     * See cs_scatter in CSparse
     */
    int scatter(int j, std::vector<int>& w, int mark, int* Ci, int nz) const;

    /// Get row() as a vector
    std::vector<int> getRow() const;

    /// Get colind() as a vector
    std::vector<int> getColind() const;

    /// Get the column for each nonzero
    std::vector<int> getCol() const;

    /// Resize
    Sparsity zz_resize(int nrow, int ncol) const;

    /// Reshape a sparsity, order of nonzeros remains the same
    Sparsity zz_reshape(int nrow, int ncol) const;

    /// Number of elements
    int numel() const;

    /// Number of non-zeros in the lower triangular half
    int sizeL() const;

    /// Number of non-zeros in the upper triangular half
    int sizeU() const;

    /// Number of non-zeros on the diagonal
    int sizeD() const;

    /** \brief Upper half-bandwidth */
    int bandwidthU() const;

    /** \brief Lower half-bandwidth */
    int bandwidthL() const;

    /// Shape
    std::pair<int, int> shape() const;

    /// Is scalar?
    bool isscalar(bool scalar_and_dense) const;

    /** \brief Check if the sparsity is empty
     *
     * A sparsity is considered empty if one of the dimensions is zero
     * (or optionally both dimensions)
     */
    bool isempty(bool both=false) const;

    /// Is dense?
    bool isdense() const;

    /** \brief  Check if the pattern is a row vector (i.e. size1()==1) */
    bool isrow() const;

    /** \brief  Check if the pattern is a column vector (i.e. size2()==1) */
    bool iscolumn() const;

    /** \brief  Check if the pattern is a row or column vector */
    bool isvector() const;

    /// Is diagonal?
    bool isdiag() const;

    /// Is square?
    bool issquare() const;

    /// Is symmetric?
    bool issymmetric() const;

    /// Is lower triangular?
    bool istril() const;

    /// is upper triangular?
    bool istriu() const;

    /// Get upper triangular part
    Sparsity zz_triu(bool includeDiagonal) const;

    /// Get lower triangular part
    Sparsity zz_tril(bool includeDiagonal) const;

    /// Get nonzeros in lower triangular part
    std::vector<int> getLowerNZ() const;

    /// Get nonzeros in upper triangular part
    std::vector<int> getUpperNZ() const;

    /// Get the dimension as a string
    std::string dimString() const;

    /// Sparsity pattern for a matrix-matrix product (details in public class)
    Sparsity patternProduct(const Sparsity& y) const;

    ///@{
    /// Union of two sparsity patterns
    Sparsity patternCombine(const Sparsity& y, bool f0x_is_zero, bool function0_is_zero,
                            std::vector<unsigned char>& mapping) const;
    Sparsity patternCombine(const Sparsity& y, bool f0x_is_zero, bool function0_is_zero) const;

    template<bool with_mapping>
    Sparsity patternCombineGen1(const Sparsity& y, bool f0x_is_zero, bool function0_is_zero,
                                std::vector<unsigned char>& mapping) const;

    template<bool with_mapping, bool f0x_is_zero, bool function0_is_zero>
    Sparsity patternCombineGen(const Sparsity& y, std::vector<unsigned char>& mapping) const;
    ///@}

    /// Take the inverse of a sparsity pattern; flip zeros and non-zeros
    Sparsity patternInverse() const;

    /// Check if two sparsity patterns are the same
    bool isEqual(const Sparsity& y) const;

    /// Check if two sparsity patterns are the same
    bool isEqual(int y_nrow, int y_ncol, const std::vector<int>& y_colind,
                 const std::vector<int>& y_row) const;

    /// Check if two sparsity patterns are the same
    bool isEqual(int y_nrow, int y_ncol, const int* y_colind, const int* y_row) const;

    /// Enlarge the matrix along the first dimension (i.e. insert rows)
    Sparsity zz_enlargeRows(int nrow, const std::vector<int>& rr, bool ind1) const;

    /// Enlarge the matrix along the second dimension (i.e. insert columns)
    Sparsity zz_enlargeColumns(int ncol, const std::vector<int>& cc, bool ind1) const;

    /// Make a patten dense
    Sparsity makeDense(std::vector<int>& mapping) const;

    /// Erase rows and/or columns - does bounds checking
    Sparsity zz_erase(const std::vector<int>& rr, const std::vector<int>& cc,
                      bool ind1, std::vector<int>& mapping) const;

    /// Erase elements
    Sparsity zz_erase(const std::vector<int>& rr, bool ind1,
                      std::vector<int>& mapping) const;

    /// Append another sparsity patten vertically (vectors only)
    Sparsity zz_appendVector(const SparsityInternal& sp) const;

    /// Append another sparsity patten horizontally
    Sparsity zz_appendColumns(const SparsityInternal& sp) const;

    /** \brief Get a submatrix
    * Does bounds checking
    * rr and rr are not required to be monotonous
    */
    Sparsity sub(const std::vector<int>& rr, const std::vector<int>& cc,
                 std::vector<int>& mapping, bool ind1) const;

    /** \brief Get a set of elements
    * Does bounds checking
    * rr is not required to be monotonous
    */
    Sparsity sub(const std::vector<int>& rr, const SparsityInternal& sp,
                 std::vector<int>& mapping, bool ind1) const;

    /// Get the index of an existing non-zero element
    int getNZ(int rr, int cc) const;

    /// Get a set of non-zero element - does bounds checking
    std::vector<int> getNZ(const std::vector<int>& rr, const std::vector<int>& cc) const;

    /// Get the nonzero index for a set of elements (see description in public class)
    void getNZ(std::vector<int>& indices) const;

    /// Does the rows appear sequentially on each col
    bool rowsSequential(bool strictly) const;

    /** \brief Remove duplicate entries
     *
     * The same indices will be removed from the mapping vector,
     * which must have the same length as the number of nonzeros
     */
    Sparsity zz_removeDuplicates(std::vector<int>& mapping) const;

    /// Get element index for each nonzero
    void find(std::vector<int>& loc, bool ind1) const;

    /// Hash the sparsity pattern
    std::size_t hash() const;

    /// Clone
    virtual SparsityInternal* clone() const { return new SparsityInternal(*this); }

    /// Print representation
    virtual void repr(std::ostream &stream) const;

    /// Print description
    virtual void print(std::ostream &stream) const;

    /** \brief Perform a unidirectional coloring
     *
     * A greedy distance-2 coloring algorithm
     * (Algorithm 3.1 in A. H. GEBREMEDHIN, F. MANNE, A. POTHEN)
     */
    Sparsity unidirectionalColoring(const Sparsity& AT, int cutoff) const;

    /** \brief Perform a star coloring
     *
     * This method can efficiently treat arrow-shaped sparsity pattern.
     * 
     *
     */
    Sparsity starColoring(int ordering, int cutoff, int mode, int threshold) const;

    /** \brief A greedy distance-3 coloring algorithm
     * See description in public class.
     */
    Sparsity starColoring1(int ordering, int cutoff) const;

    /** \brief An improved distance-2 coloring algorithm
     * See description in public class.
     */
    Sparsity starColoring2(int ordering, int cutoff) const;

    /// Order the columns by decreasing degree
    std::vector<int> largestFirstOrdering() const;

    /// Permute rows and/or columns
    Sparsity pmult(const std::vector<int>& p, bool permute_rows=true, bool permute_cols=true,
                   bool invert_permutation=false) const;

    /** \brief Print a textual representation of sparsity */
    void spy(std::ostream &stream) const;

    /** \brief Print a compact description of the sparsity pattern */
    void printCompact(std::ostream &stream) const;

    /// Generate a script for Matlab or Octave which visualizes the sparsity using the spy command
    void spyMatlab(const std::string& mfile) const;
};

} // namespace casadi
/// \endcond

#endif // CASADI_SPARSITY_INTERNAL_HPP
