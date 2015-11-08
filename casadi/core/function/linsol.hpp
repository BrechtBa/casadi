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


#ifndef CASADI_LINSOL_HPP
#define CASADI_LINSOL_HPP

#include "function_internal.hpp"
#include "plugin_interface.hpp"

/// \cond INTERNAL

namespace casadi {

  /** Internal class
      @copydoc Linsol_doc
  */
  class CASADI_EXPORT Linsol : public FunctionInternal, public PluginInterface<Linsol> {
  private:
    Sparsity sparsity_;
    int nrhs_;
  public:
    /// Constructor
    Linsol(const std::string& name, const Sparsity& sparsity, int nrhs);

    /// Destructor
    virtual ~Linsol();

    ///@{
    /** \brief Number of function inputs and outputs */
    virtual size_t get_n_in() const { return LINSOL_NUM_IN;}
    virtual size_t get_n_out() const { return LINSOL_NUM_OUT;}
    ///@}

    /// @{
    /** \brief Sparsities of function inputs and outputs */
    virtual Sparsity get_sparsity_in(int ind) const;
    virtual Sparsity get_sparsity_out(int ind) const;
    /// @}

    /// Initialize
    virtual void init();

    /// Solve the system of equations
    virtual void evalD(const double** arg, double** res, int* iw, double* w, void* mem);

    /// Prepare the factorization
    virtual void linsol_prepare(const double** arg, double** res, int* iw, double* w, void* mem);

    /// Solve the system of equations, using internal vector
    virtual void linsol_solve(bool tr);

    /// Solve the system of equations
    virtual void linsol_solve(double* x, int nrhs, bool tr);

    /// Create a solve node
    virtual MX linsol_solve(const MX& A, const MX& B, bool tr);

    /// Evaluate SX, possibly transposed
    virtual void linsol_evalSX(const SXElem** arg, SXElem** res, int* iw, SXElem* w, void* mem,
                               bool tr, int nrhs);

    /** \brief Quickfix to avoid segfault, #1552 */
    virtual bool canEvalSX() const {return true;}

    /// Evaluate SX
    virtual void evalSX(const SXElem** arg, SXElem** res, int* iw, SXElem* w, void* mem) {
      linsol_evalSX(arg, res, iw, w, 0, false, output(LINSOL_X).size2());
    }

    /** \brief Calculate forward mode directional derivatives */
    virtual void linsol_forward(const std::vector<MX>& arg, const std::vector<MX>& res,
                                const std::vector<std::vector<MX> >& fseed,
                                std::vector<std::vector<MX> >& fsens, bool tr);

    /** \brief Calculate reverse mode directional derivatives */
    virtual void linsol_reverse(const std::vector<MX>& arg, const std::vector<MX>& res,
                                const std::vector<std::vector<MX> >& aseed,
                                std::vector<std::vector<MX> >& asens, bool tr);

    /** \brief  Propagate sparsity forward */
    virtual void linsol_spFwd(const bvec_t** arg, bvec_t** res, int* iw, bvec_t* w, void* mem,
                              bool tr, int nrhs);

    /** \brief  Propagate sparsity backwards */
    virtual void linsol_spAdj(bvec_t** arg, bvec_t** res, int* iw, bvec_t* w, void* mem,
                              bool tr, int nrhs);

    ///@{
    /// Propagate sparsity through a linear solve
    virtual void linsol_spsolve(bvec_t* X, const bvec_t* B, bool tr) const;
    virtual void linsol_spsolve(DMatrix& X, const DMatrix& B, bool tr) const;
    ///@}

    /// Dulmage-Mendelsohn decomposition
    std::vector<int> rowperm_, colperm_, rowblock_, colblock_;

    /// Get sparsity pattern
    int nrow() const { return input(LINSOL_A).size1();}
    int ncol() const { return input(LINSOL_A).size2();}
    int nnz() const { return input(LINSOL_A).nnz();}
    const int* row() const { return input(LINSOL_A).row();}
    const int* colind() const { return input(LINSOL_A).colind();}

    // Creator function for internal class
    typedef Linsol* (*Creator)(const std::string& name, const Sparsity& sp, int nrhs);

    // No static functions exposed
    struct Exposed{ };

    /// Collection of solvers
    static std::map<std::string, Plugin> solvers_;

    /// Infix
    static const std::string infix_;

    // Get name of the plugin
    virtual const char* plugin_name() const { return "none";}

    // Memory
    const double *a_, *b_;
    double *x_;
    const double **arg1_;
    double **res1_;
    int *iw_;
    double *w_;
  };


} // namespace casadi
/// \endcond

#endif // CASADI_LINSOL_HPP
