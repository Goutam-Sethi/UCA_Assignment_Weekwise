#!/bin/bash

# -----------------------------------------------------------------------------
# Cleaning Up Production Web Server Logs
#
# Problem Statement:
# You are on call for an e-commerce platform. During a routine audit, you
# notice that a legacy script generated a server_access.log file containing
# sensitive user details and outdated system formatted strings that need
# cleaning before the log can be safely archived.
#
# Task:
# Write a sed solution to perform the following cleanup tasks directly
# in-place on server_access.log.
#
# Requirements:
# 1. Mask all 16-digit credit card numbers in the following formats:
#    - 4532-8901-2345-6789
#    - 4532890123456789
#    Replace them with:
#    XXXX-XXXX-XXXX-XXXX
#
# 2. Replace all occurrences of:
#    HTTP/1.0
#    with:
#    HTTP/1.1
#
# 3. Remove every line that starts with the '#' character,
#    as these are debug comment lines.
#
# Expected Result:
# - Credit card numbers are masked.
# - HTTP/1.0 is updated to HTTP/1.1.
# - Comment lines are removed.
# - Changes are made directly in server_access.log using sed.
# -----------------------------------------------------------------------------

sed -E -i \
-e 's/[0-9]{4}-[0-9]{4}-[0-9]{4}-[0-9]{4}/XXXX-XXXX-XXXX-XXXX/g' \
-e 's/[0-9]{16}/XXXX-XXXX-XXXX-XXXX/g' \
-e 's/HTTP\/1\.0/HTTP\/1.1/g' \
-e '/^#/d' \
server_access.log
