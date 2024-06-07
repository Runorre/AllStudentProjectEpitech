#!/bin/sh
cut -d: -f5 | cut -d" " -f2 |grep -ci "^$1"

