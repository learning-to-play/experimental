echo 1
set -xv
echo 2
VAR=$@
cd wrong/path
set +xv
echo 3
