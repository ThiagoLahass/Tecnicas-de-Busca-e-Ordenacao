
merge-sort_top-down_recursivo_sem-otimizacao: clean
	@gcc -c merge-sort_top-down_recursivo_sem-otimizacao.c
	@gcc -c client.c
	@gcc -o prog *.o

merge-sort_top-down_recursivo_cut-off: clean
	@gcc -c insert_sort.c
	@gcc -c merge-sort_top-down_recursivo_cut-off.c
	@gcc -c client.c
	@gcc -o prog *.o

merge-sort_top-down_recursivo_merge-skip: clean
	@gcc -c merge-sort_top-down_recursivo_merge-skip.c
	@gcc -c client.c
	@gcc -o prog *.o

merge-sort_bottom-up_sem-otimizacao: clean
	@gcc -c merge-sort_bottom-up_sem-otimizacao.c
	@gcc -c client.c
	@gcc -o prog *.o

run_nearly_sorted_100k:
	./prog 100000 <in/nearly_sorted/100000.txt

run_nearly_sorted_1M:
	./prog 1000000 <in/nearly_sorted/1000000.txt

run_reverse_sorted_100k:
	./prog 100000 <in/reverse_sorted/100000.txt

run_reverse_sorted_1M:
	./prog 1000000 <in/reverse_sorted/1000000.txt

run_sorted_100k:
	./prog 100000 <in/sorted/100000.txt

run_sorted_1M:
	./prog 1000000 <in/sorted/1000000.txt

run_unif_rand_100k:
	./prog 100000 <in/unif_rand/100000.txt

run_unif_rand_1M:
	./prog 1000000 <in/unif_rand/1000000.txt

runAll: run_nearly_sorted_100k run_nearly_sorted_1M run_reverse_sorted_100k run_reverse_sorted_1M run_sorted_100k run_sorted_1M run_unif_rand_100k run_unif_rand_1M
 
clean:
	@rm *.o
	@rm prog