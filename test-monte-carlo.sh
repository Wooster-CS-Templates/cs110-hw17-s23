#! /bin/bash

if ! [[ -x monte-carlo ]]; then
    echo "program monte-carlo executable does not exist"
    exit 1
fi

tester/run-tests.sh -d tests/monte-carlo-args
