//#include <boost/multiprecision/cpp_int.hpp>
//#include <boost/multiprecision/miller_rabin.hpp>
//#include <boost/random.hpp>
//#include <boost/random/random_device.hpp>
//
//using namespace boost::multiprecision;
//using namespace boost::random;
//int main() {
//	boost::random::random_device rd;
//	std::seed_seq seq{ rd(), rd(), rd(), rd() };
//	boost::random::mt19937 gen_base(seq);  //feeding seed sequence for greater randomness
//	boost::random::independent_bits_engine<boost::random::mt19937, 2048, cpp_int> gen(gen_base);
//	cpp_int n;
//	do
//	{
//		n = gen();
//		n |= 1; //forcing no. to be odd to remove unnecessary cases
//	} while (!miller_rabin_test(n, 50));
//	
//}
//safe prime
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/miller_rabin.hpp>
#include <boost/random.hpp>
#include <boost/random/random_device.hpp>

using namespace boost::multiprecision;
using namespace boost::random;

cpp_int generate_safe_prime(unsigned bits) {
    
    static random_device rd;
    static mt19937 gen_base(rd());

    // Generate q with (bits-1) bits
    independent_bits_engine<mt19937, 2047, cpp_int> gen(gen_base);

    cpp_int q, p;

    while (true) {
        // Step 1: generate random q
        q = gen();
        q |= 1;              // make odd

        // Step 2: check if q is prime
        if (!miller_rabin_test(q, 40))
            continue;

        // Step 3: compute p = 2q + 1
        p = 2 * q + 1;

        // Step 4: check if p is prime
        if (miller_rabin_test(p, 40))
            return p;   // safe prime found
    }
}