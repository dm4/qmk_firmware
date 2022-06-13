#!/bin/bash

set -e

# get latest dm4 branch
git co dm4
git pull

# pull from upstream/master
git co master
git pull

# push to dm4/master
git push origin master

git co -
git rebase master
