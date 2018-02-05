for f in champs/*.cor
do
	./corewar $1 $f | grep 'won'
	./corewar $f $1 | grep 'won'
done
