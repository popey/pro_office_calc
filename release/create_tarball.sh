#!/bin/bash

# Uses git archive to construct archive of the current HEAD and places it into the build directory.
# The archive name will be of the form procalc_1.0.15+16SNAPSHOT20180719015812.orig.tar.gz for
# snapshots, or procalc_1.0.15.orig.tar.gz for stable builds.

if [ ! -d src ]; then
  echo "Please run create_tarball.sh from project root. Aborting"
  exit 1
fi

packageName="procalc"
destination="./build"
commit="HEAD"
snapshot=false

while getopts "c:v:s" opt
do
  case $opt in
    c) commit="$OPTARG"
       ;;
    s) snapshot=true
       ;;
    v) version="$OPTARG"
       ;;
  esac
done

if [ -z "$version" ]; then
  # If the version arg is missing and the commit is the current HEAD, we can read the version
  # number from the VERSION file

  if [ "$commit" != "HEAD" ]; then
    printf "Expects version arg for commits other than HEAD\n"
    printf "Usage: $0 [-c <commit> -v <version>] [-s]\n"
    exit 1
  fi

  version=$(cat ./VERSION)
fi

if [ "$commit" = "HEAD" ]; then
  if [ ! -z "$(git status --porcelain)" ]; then
    printf "Warning: There are uncommitted changes. Building from HEAD.\n"
  fi
fi

if [ "$snapshot" = true ]; then
  timestamp=$(date -u +%Y%m%d%H%M%S)
  minor="${version: -1}"
  minorPlus1=$((minor + 1))
  suffix="+${minorPlus1}SNAPSHOT${timestamp}"
else
  suffix=""
fi

printf "Building archive... "
mkdir -p "$destination"

tmpArchiveName="tmp.tar.gz"
git archive --format=tar.gz -o "$destination/$tmpArchiveName" "$commit"

cd "$destination"

unpackedDir="${packageName}-${version}${suffix}"
archiveName="${packageName}_${version}${suffix}.orig.tar.gz"

mkdir -p "$unpackedDir"

tar -xkf "$tmpArchiveName" -C "$unpackedDir"
rm "$tmpArchiveName"

tar -czf  "$archiveName" "$unpackedDir"
rm -r "$unpackedDir"

cd ..
printf "Done\n"
