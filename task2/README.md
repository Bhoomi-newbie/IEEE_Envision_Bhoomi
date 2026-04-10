This task was based on on implementing a Diffie Hillman key exchange Algorithm in C++.
<br>
1) For handling arbitrarily large numbers, I used- boost::multiprecision::cpp_int datatype of boost library
2) for generation of large primes- method: first generate a random large number and check if its prime using miller rabin primality test
   implementation- used mersian twister engine to generate random sequence of numbers,
   which were fed into the independent bits engine to generate a random number of required bits
3) I took help of AI in this and it suggested to use safe primes where p is a prime such that p=2q+1 and q is also a prime.
   In such a case, 2 can be used as the generator for the key exchange.

   
