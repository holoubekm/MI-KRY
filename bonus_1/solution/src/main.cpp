#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <fstream>
#include <chrono>
#include <gmp.h>

using namespace std;

mpz_t zero, one, two, three;
mpz_t p, q, g, sha1, nsha1, k;
mpz_t t1, t2, t3, t4, t5;
mpz_t r, s, x;

void exp(mpz_t result, mpz_t base, mpz_t exponent, mpz_t modulus) {
    mpz_t tmp_base, tmp_exponent;
    mpz_init(tmp_base);
    mpz_init(tmp_exponent);
    mpz_set(tmp_base, base);
    mpz_set(tmp_exponent, exponent);

    mpz_set_ui(result, 1);
   

    while (mpz_cmp(exponent, zero) > 0) {
        if(mpz_tstbit(exponent, 0)) {
            mpz_mul(result, result, base);
            mpz_mod(result, result, modulus);
        }
        mpz_div(exponent, exponent, two);
        mpz_mul(base, base, base);
        mpz_mod(base, base, modulus);
    }
    mpz_set(base, tmp_base);
    mpz_set(exponent, tmp_exponent);
    mpz_clear(tmp_base);
    mpz_clear(tmp_exponent);
}

void exp(mpz_t result, mpz_t base, mpz_t exponent) {
    mpz_t tmp_base, tmp_exponent;
    mpz_init(tmp_base);
    mpz_init(tmp_exponent);
    mpz_set(tmp_base, base);
    mpz_set(tmp_exponent, exponent);

    mpz_set_ui(result, 1);
   

    while (mpz_cmp(exponent, zero) > 0) {
        if(mpz_tstbit(exponent, 0)) {
            mpz_mul(result, result, base);
        }
        mpz_div(exponent, exponent, two);
        mpz_mul(base, base, base);
    }
    mpz_set(base, tmp_base);
    mpz_set(exponent, tmp_exponent);
    mpz_clear(tmp_base);
    mpz_clear(tmp_exponent);
}

void mult(mpz_t result, mpz_t multiplier, mpz_t multiplicand, mpz_t modulus) {
    mpz_mul(result, multiplier, multiplicand);
    mpz_mod(result, result, modulus);
}

void inverse(mpz_t result, mpz_t a, mpz_t b) {
    mpz_t b0, t, q, x0, x1, tmp_a, tmp_b;
    mpz_init(b0);
    mpz_init(t);
    mpz_init(q);
    mpz_init(x0);
    mpz_init(x1);
    mpz_init(tmp_a);
    mpz_init(tmp_b);

    mpz_set(b0, b);
    mpz_set(x0, zero);
    mpz_set(x1, one);
    mpz_set(tmp_a, a);
    mpz_set(tmp_b, b);

    if(mpz_cmp(b, one) == 0) {
        mpz_set(result, one);
        return;
    }

    while(mpz_cmp(tmp_a, one) > 0) {
        mpz_div(q, tmp_a, tmp_b);
        mpz_set(t, tmp_b);
        mpz_mod(tmp_b, tmp_a, tmp_b);
        mpz_set(tmp_a, t);
        mpz_set(t, x0);
        mpz_mul(result, q, x0);
        mpz_sub(x0, x1, result);
        mpz_set(x1, t);
    }
    if(mpz_cmp(x1, zero) < 0) 
        mpz_add(x1, x1, b0);
    mpz_set(result, x1);

    mpz_clear(b0);
    mpz_clear(t);
    mpz_clear(q);
    mpz_clear(x0);
    mpz_clear(x1);
    mpz_clear(tmp_a);
    mpz_clear(tmp_b);
}

void gcd(mpz_t result, mpz_t a, mpz_t b) {
    mpz_t tmp_b, r;
    mpz_init(r);
    mpz_init(tmp_b);
    mpz_set(tmp_b, b);
    mpz_set(result, a);

    while (mpz_cmp(tmp_b, zero) > 0) {
        mpz_mod(r, result, tmp_b);
        mpz_set(result, tmp_b);
        mpz_set(tmp_b, r);
    }
    mpz_clear(r);
    mpz_clear(tmp_b);
}

int main(int argc, char* argv[]) {

    mpz_init(zero);
    mpz_init(one);
    mpz_init(two);
    mpz_init(three);

    mpz_set_ui(zero, 0);
    mpz_set_ui(one, 1);
    mpz_set_ui(two, 2);
    mpz_set_ui(three, 3);

    mpz_init(p);
    mpz_init(k);
    mpz_init(q);
    mpz_init(g);
    mpz_init(sha1);
    mpz_init(nsha1);

    mpz_init(t1);
    mpz_init(t2);
    mpz_init(t3);
    mpz_init(t4);
    mpz_init(t5);
    mpz_init(r);
    mpz_init(s);
	mpz_init(x);

    mpz_set_str(p, "00af144ae2b1e1aec726b6532409eb58f9030fdf8357ea45a191a0903334b95da48b0464944b7a7186d83efac96ddf795f17c1b9e2155c47aae3508321a72724cb502c5b5616e890aab35cdd339dda8bf9a6eca788933e8aecee989031af8f887864189d25c0e366038e1e16018688893fc82ddfb88dc35fcbc16e355ba2bccc59", 16);
    mpz_set_str(q, "00a645825b7a45e43e3d4d0a0aa7448a7149e6d187", 16);
    mpz_set_str(g, "3d1690094ebd2c5da6ff2110ab9340e2d51856186101219b4d8cde5ae7feaea6a8dabf34bf0457d612f9a5525c117a9c6652f8ac5f63d19c39efd0a8641f1982b427d82427177057039fefcc705c4fa0c37e1f0e084ad6dc0d436a52ab832b8af221e6f9daf59354423c20b626ed590dd6b7bc34076525f74ec03208adb7fb67", 16);

    // k to be found from the file
    // mpz_set_str(k, "2FDB6A467156DD10272D96963855B09FC1C64F60", 16);

    // SHA1 of the file to be signed
    mpz_set_str(sha1, "74f61ebadc8d61184fb426ab65ce3344ad249255", 16);

    //Extracted from the public signature
    mpz_set_str(r, "6ca9ef20ba1fa11fb0129b323776069b6c7ec7a5", 16);
    mpz_set_str(s, "948cad01e9461a1a47399328972170ad91f3d04e", 16);

    // To be computed
    // mpz_set_str(x, "4b84157bd729be5fa36e0767fbc1bb4f9edfc4fc", 16);

    std::ifstream infile("ks.txt");
    string line;

    // For each "k" compute - "r"
    // In the list of precomputed "k"s find "r" matching the public signature we were given

    while(getline(infile, line)) {
        mpz_set_str(k, line.c_str(), 16);
        exp(t1, g, k, p);
        mpz_mod(t2, t1, q);

        if(mpz_cmp(t2, r) == 0) {
            auto res = mpz_get_str(NULL, 16, r);
            cout << "Found the matching k: [" << line << "] for the extracted r: [" << res << "]" << endl;
            break;
        }
        // printf("%s\n", mpz_get_str(NULL, 16, r));
    }
    infile.close();


    // Now let compute the private key
    // ((sk - H(m))r^-1 mod q = x
    mult(t1, s, k, q);
    mpz_sub(t2, t1, sha1);
    inverse(t3, r, q);
    mult(t1, t2, t3, q);
    mpz_mod(x, t1, q);
    printf("Private key: %s\n", mpz_get_str(NULL, 16, x));




    // Let's check whether the private key "x" matches "r" and "s"
    // printf("%s\n", mpz_get_str(NULL, 16, x));
    // r = (g^k mod p) mod q
    // s = (k^-1 (H(m) + xr)) mod q
    exp(t1, g, k, p);
    mpz_mod(r, t1, q);

        
    inverse(t1, k, q);
    mult(t2, x, r, q);
    mpz_add(t3, t2, sha1);
    mult(s, t1, t3, q);

    printf("r: %s\n", mpz_get_str(NULL, 16, r));
    printf("s: %s\n", mpz_get_str(NULL, 16, s));

    mpz_clear(zero);
    mpz_clear(one);
    mpz_clear(two);
    mpz_clear(three);

    mpz_clear(p);
    mpz_clear(k);
    mpz_clear(q);
    mpz_clear(g);
    mpz_clear(sha1);
    mpz_clear(nsha1);

    mpz_clear(t1);
    mpz_clear(t2);
    mpz_clear(t3);
    mpz_clear(t4);
    mpz_clear(t5);
    mpz_clear(r);
    mpz_clear(s);
	mpz_clear(x);

	return 0;
}