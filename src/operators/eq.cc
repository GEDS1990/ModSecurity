/*
 * ModSecurity, http://www.modsecurity.org/
 * Copyright (c) 2015 Trustwave Holdings, Inc. (http://www.trustwave.com/)
 *
 * You may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * If any of the files related to licensing are missing or if you have any
 * other questions related to licensing please contact Trustwave Holdings, Inc.
 * directly using the email address security@modsecurity.org.
 *
 */

#include "operators/eq.h"

#include <string>

#include "operators/operator.h"

namespace ModSecurity {
namespace operators {


bool Eq::evaluate(Assay *assay, const std::string &input) {
    int p = 0;
    int i = 0;
    bool eq = false;

    try {
        p = std::stoi(param);
    } catch (...) {
        p = 0;
    }
    try {
        i = std::stoi(input);
    } catch (...) {
        i = 0;
    }

    eq = p == i;

    if (negation) {
        return !eq;
    }

    return eq;
}


}  // namespace operators
}  // namespace ModSecurity
