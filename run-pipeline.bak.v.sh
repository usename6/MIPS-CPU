#!/usr/bin/env bash

TESTER_BACKENDS=verilator sbt "test:run-main Pipeline.Launcher $1"
