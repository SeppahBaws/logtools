

if echo $* | grep -e "--flag" -q
then
    echo ">>>> Running with flag"
else
    echo ">>>> Running without flag"
fi