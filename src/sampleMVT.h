// sampleMVT.h
// =============================================================================
// include guard
#ifndef SAMPLEMVT_H
#define SAMPLEMVT_H

// =============================================================================
// included dependencies
# include <RcppArmadillo.h>
# include "mvtSampler.h"

// =============================================================================
// sampleMVT function header


//' @title Sample mixture of multivariate t-distributions with batch effects
//' @description Performs MCMC sampling for a MVT mixture model with batch effects.
//' @param X The data matrix to perform clustering upon (items to cluster in rows).
//' @param K The number of components to model (upper limit on the number of 
//' clusters found).
//' @param B The number of batches to model.
//' @param labels Vector item labels to initialise from.
//' @param batch_vec Observed batch labels.
//' @param mu_proposal_window The standard deviation for the Gaussian proposal 
//' density of the cluster means.
//' @param cov_proposal_window The degrees of freedom for the Wishart proposal 
//' density of the cluster covariances.
//' @param m_proposal_window The standard deviation for the Gaussian proposal 
//' density of the batch mean effects.
//' @param S_proposal_window The rate for the Gamma proposal density of the 
//' batch scale.
//' @param t_df_proposal_window The rate for the Gamma proposal density of the 
//' cluster degrees of freedom.
//' @param R The number of iterations to run for.
//' @param thin thinning factor for samples recorded.
//' @param concentration Vector of concentrations for mixture weights 
//' (recommended to be symmetric).
//' @param m_scale The scale hyperparameter for the batch shift prior 
//' distribution.
//' @param rho The shape of the prior distribution for the batch scale.
//' @param theta The scale of the prior distribution for the batch scale.
//' @param initial_mu A P x K matrix of initial values for the class means.
//' @param initial_cov A P x P x K cube of initial values for the class 
//' covariance matrices.
//' @param initial_df A K vector of initial values for the class degrees of
//' freedom.
//' @param initial_m A P x B matrix of initial values for the batch shift 
//' effects.
//' @param initial_S A P x B matrix of initial values for the batch scales.
//' @param mu_initialised Bool indicating if the class means are initialised by
//' the user. If ``false`` then initial values are drawn from the prior 
//' distribution.
//' @param cov_initialised Bool indicating if the class covariance matrices are 
//' initialised by the user. If ``false`` then initial values are drawn from the
//' prior distribution.
//' @param df_initialised Bool indicating if the class degrees of freedom are 
//' initialised by the user. If ``false`` then initial values are drawn from the 
//' prior distribution.
//' @param m_initialised Bool indicating if the batch shift effects are 
//' initialised by the user. If ``false`` then initial values are drawn from the
//' prior distribution.
//' @param S_initialised Bool indicating if the batch scales are initialised by 
//' the user. If ``false`` then initial values are drawn from the prior 
//' distribution.
//' @return Named list of the different quantities drawn by the sampler.
// [[Rcpp::export]]
Rcpp::List sampleMVT (
    arma::mat X,
    arma::uword K,
    arma::uword B,
    arma::uvec labels,
    arma::uvec batch_vec,
    double mu_proposal_window,
    double cov_proposal_window,
    double m_proposal_window,
    double S_proposal_window,
    double t_df_proposal_window,
    arma::uword R,
    arma::uword thin,
    arma::vec concentration,
    double m_scale,
    double rho,
    double theta,
    arma::mat initial_mu,
    arma::cube initial_cov,
    arma::vec initial_df,
    arma::mat initial_m,
    arma::mat initial_S,
    bool mu_initialised,
    bool cov_initialised,
    bool df_initialised,
    bool m_initialised,
    bool S_initialised
);

#endif /* SAMPLEMVT_H */