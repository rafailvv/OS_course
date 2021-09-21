if [ ! -f ex2.txt ]; then
	echo 0 > ex2.txt
fi

count=0

while [ $count -lt 10 ]; 
do
	count=$(($count + 1))

	if ln ex2.txt ex2.lock
	then
		n=$(tail -1 ex2.txt)
		echo $((n+1)) >> ex2.txt
		rm ex2.lock
	fi
done