#!/bin/bash
shopt -s extglob

./install-demo-data.sh
./install-full-data.sh

if [ $# -eq 0 ]; then
	FILTER=@(*release|*demo)
else
	FILTER=$1
fi

SOURCEDIR="$(pwd)"
BUILDDIR="${SOURCEDIR}/build"
PKGDIR="$(pwd)/packages"

if [ ! -d "${PKGDIR}" ]; then
	mkdir "${PKGDIR}"
else
	rm -rf "${PKGDIR}/*"
fi

for i in $BUILDDIR/$FILTER ; do
	echo
	echo "[ Building $(basename $i) ]"
	echo $i
	cd $i
	make package
	mv *.@(rpm|deb|tar.bz2|zip) "${PKGDIR}"
	echo "[ Leaving $(basename $i) ]"
	echo
done
