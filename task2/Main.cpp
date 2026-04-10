#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/miller_rabin.hpp>
#include <boost/random.hpp>
#include <boost/random/random_device.hpp>

using namespace boost::multiprecision;
using namespace boost::random;

boost::random::random_device rd;
std::seed_seq seq{ rd(), rd(), rd(), rd() };
mt19937 gen_base(seq);

class Crypto {
	cpp_int private_key1;
	cpp_int private_key2;
	cpp_int public_key1;
	cpp_int public_key2;
	cpp_int secret_key;
	cpp_int prime;
	int gen = 2;

	cpp_int generate_private_key() {   //to generate random numbers for private keys of alice and bob
		private_key1 = gen_base();
		private_key2 = gen_base();
		 };

    cpp_int generate_safe_prime() {   

        static random_device rd;
        static mt19937 gen_base(rd());

        // Generate q with (2048-1) bits
        independent_bits_engine<mt19937, 2047, cpp_int> gen(gen_base);

        cpp_int q, p;

        while (true) {
            // Step 1: generate random q
            q = gen();
            q |= 1;              // make odd
            q |= (cpp_int(1) << (2048 - 2)); // to ensure correct bit length
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

    cpp_int modular_exponentiation() {};

};