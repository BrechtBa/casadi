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


#ifndef CASADI_DLE_TO_LR_DLE_HPP
#define CASADI_DLE_TO_LR_DLE_HPP

#include "../core/function/dle_internal.hpp"
#include "../core/function/lr_dle_internal.hpp"
#include "../core/function/adaptor.hpp"
#include <casadi/solvers/casadi_dlesolver_lrdle_export.h>

/** \defgroup plugin_LrDleSolver_dle
 Solving the Discrete Lyapunov Equations with a
 Low-rank Discrete Lyapunov Equations solver

*/
/** \pluginsection{DleSolver,lrdle} */

/// \cond INTERNAL
namespace casadi {

  /** \brief \pluginbrief{DleSolver,lrdle}

   @copydoc DLE_doc
   @copydoc plugin_DleSolver_lrdle

       \author Joris Gillis
      \date 2014

  */
  class CASADI_DLESOLVER_LRDLE_EXPORT DleToLrDle : public DleInternal,
    public Adaptor<DleToLrDle, LrDleInternal>,
    public Wrapper<DleToLrDle>   {
  public:
    /** \brief  Constructor
     * \param st \structargument{Dle}
     */
    DleToLrDle(const std::map<std::string, Sparsity>& st);

    /** \brief  Destructor */
    virtual ~DleToLrDle();

    /** \brief  Clone */
    virtual DleToLrDle* clone() const;

    /** \brief  Deep copy data members */
    virtual void deepCopyMembers(std::map<SharedObjectNode*, SharedObject>& already_copied);

    /** \brief  Create a new solver */
    virtual DleToLrDle* create(const std::map<std::string, Sparsity>& st) const {
        return new DleToLrDle(st);
    }

    /** \brief  Create a new DLE Solver */
    static DleInternal* creator(const std::map<std::string, Sparsity>& st) {
      return new DleToLrDle(st);
    }

    /** \brief  Print solver statistics */
    virtual void printStats(std::ostream &stream) const {}

    /** \brief  evaluate */
    virtual void evaluate();

    /** \brief  Initialize */
    virtual void init();

    ///@{
    /** \brief Generate a function that calculates \a nfwd forward derivatives */
    virtual Function getDerForward(const std::string& name, int nfwd, Dict& opts);
    virtual int numDerForward() const { return 64;}
    ///@}

    ///@{
    /** \brief Generate a function that calculates \a nadj adjoint derivatives */
    virtual Function getDerReverse(const std::string& name, int nadj, Dict& opts);
    virtual int numDerReverse() const { return 64;}
    ///@}

    /// A documentation string
    static const std::string meta_doc;

    /// Solve with
    LrDleSolver solver_;
  };

} // namespace casadi
/// \endcond
#endif // CASADI_LR_DLE_TO_LR_DLE_HPP
