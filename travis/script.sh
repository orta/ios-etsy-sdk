#!/bin/sh
set -e

xctool -project ios-etsy-sdk.xcodeproj -scheme Kiwi build
xctool -project ios-etsy-sdk.xcodeproj -scheme ios-etsy-sdk build test
