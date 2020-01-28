#include <iostream>
#include <string>
#include <cstring>
#include <memory>

#define INTERFACE "enp0s3"

#define CHECKER_GATEWAY "http://192.168.0.146/checker/"
#include <unistd.h>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <curl/curl.h>
#include "services.h"
#include "crypto.hpp"
#include "util.hpp"


int main(int argc, char **argv)
{
    byte iv[BLOCK_SIZE];
    byte *key = (byte *) "2c1cd7ae142f3499f8db3813eef961b2";
    EVP_add_cipher(EVP_aes_256_cbc());

    crypto::gen_params(iv);

    /**
     * packet format for 5 services:
     * IP:1:1:1:1:1 - 1 is up
     * IP:0:1:0:1:0 - 0 is down
     */

    char p[100];

    std::snprintf(p, sizeof(p), "%s:%d", util::getLocalIP(), util::getServiceStatus("nginx"), util::getServiceStatus("apache2"));
    p[strlen(p)] = '\0';

    secure_string ptext = p;

    secure_string ctext, rtext;

    crypto::aes_encrypt(key, iv, ptext, ctext);
    ctext.append("::");
    ctext.append((char *)iv, BLOCK_SIZE);

    OPENSSL_cleanse(iv, BLOCK_SIZE);

    secure_string b64text = crypto::base64_encode(ctext);

    // TODO: Push to the checker's gateway
    util::pushServiceStatus(b64text);

    exit(EXIT_SUCCESS);
}
