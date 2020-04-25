#! /bin/bash

read -p "Enter no. n: " N

#Increment pattern
COUNT=0
while [ $COUNT -le $N ]
	do
		INNER_COUNT=$COUNT
		while [ $INNER_COUNT -ge 0 ]
			do
				echo -n $INNER_COUNT ""
				((INNER_COUNT--))
		done
		echo ""
	((COUNT++))
done

#Decrement pattern
COUNT=$((N-1))
while [ $COUNT -ge 0 ]
	do
		INNER_COUNT=$COUNT
		while [ $INNER_COUNT -ge 0 ]
			do
				echo -n $INNER_COUNT ""
				((INNER_COUNT--))
		done
		echo ""
	((COUNT--))
done

unset COUNT
unset N