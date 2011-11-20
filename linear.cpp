#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/lu.hpp>
//#include "ubMatrix.hpp"

int main () {
    using namespace boost::numeric::ublas;
    matrix<double> m (3, 3);
    for (unsigned i = 0; i < m.size1 (); ++ i){
        for (unsigned j = 0; j < m.size2 (); ++ j){
            m (i, j) = double(3 * i*i + j*j);
        }
    }
    m(0,0)=5.;
    m(0,1)=15.;

    std::cout << m << std::endl;
int res(boost::numeric::ublas::lu_factorize<matrix<double> >(m));
std::cout<<"res="<<res<<std::endl;


    triangular_matrix<double, boost::numeric::ublas::unit_lower> lm = boost::numeric::ublas::triangular_adaptor< boost::numeric::ublas::matrix<double>,  boost::numeric::ublas::unit_lower>(m);
    triangular_matrix<double,  boost::numeric::ublas::upper> um =  boost::numeric::ublas::triangular_adaptor< boost::numeric::ublas::matrix<double>,  boost::numeric::ublas::upper>(m);
    std::cout << "Lower is:" <<lm<< std::endl;
    std::cout << "Upper is:" <<um<< std::endl;
    boost::numeric::ublas::vector<double> cn(3);
    for(int i=0;i<3;i++) {
            cn(i)=1.;
    }
    //boost::numeric::ublas::vector<double> dn(3);
    boost::numeric::ublas::inplace_solve(lm,cn, boost::numeric::ublas::lower_tag());
    boost::numeric::ublas::inplace_solve(um,cn, boost::numeric::ublas::upper_tag());
    std::cout<<"cn="<<cn<<std::endl;

    return 0;

}
