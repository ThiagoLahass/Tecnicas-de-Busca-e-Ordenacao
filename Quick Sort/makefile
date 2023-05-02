
quick-sort_top-down_recursivo_sem-otimizacao: clean
	@gcc -c quick-sort_top-down_recursivo_sem-otimizacao.c
	@gcc -c client.c
	@gcc -o prog *.o

quick-sort_top-down_recursivo_cut-off: clean
	@gcc -c insert_sort.c
	@gcc -c quick-sort_top-down_recursivo_cut-off.c
	@gcc -c client.c
	@gcc -o prog *.o

quick-sort_top-down_recursivo_mediana-de-3: clean
	@gcc -c quick-sort_top-down_recursivo_mediana-de-3.c
	@gcc -c client.c
	@gcc -o prog *.o

quick-sort_top-down_recursivo_mediana-de-3_cut-off: clean
	@gcc -c insert_sort.c
	@gcc -c quick-sort_top-down_recursivo_mediana-de-3_cut-off.c
	@gcc -c client.c
	@gcc -o prog *.o

quick-sort_bottom-up_sem-otimizacao: clean
	@gcc -c quick-sort_bottom-up_sem-otimizacao.c
	@gcc -c client.c
	@gcc -o prog *.o

run_nearly_sorted_100k:
	./prog 100000 <in/nearly_sorted/100000.txt

run_nearly_sorted_1M:
	./prog 1000000 <in/nearly_sorted/1000000.txt

run_nearly_sorted_10M:
	./prog 10000000 <in/nearly_sorted/10000000.txt

run_reverse_sorted_100k:
	./prog 100000 <in/reverse_sorted/100000.txt

run_reverse_sorted_1M:
	./prog 1000000 <in/reverse_sorted/1000000.txt

run_reverse_sorted_10M:
	./prog 10000000 <in/reverse_sorted/10000000.txt

run_sorted_100k:
	./prog 100000 <in/sorted/100000.txt

run_sorted_1M:
	./prog 1000000 <in/sorted/1000000.txt

run_sorted_10M:
	./prog 10000000 <in/sorted/10000000.txt

run_unif_rand_100k:
	./prog 100000 <in/unif_rand/100000.txt

run_unif_rand_1M:
	./prog 1000000 <in/unif_rand/1000000.txt

run_unif_rand_10M:
	./prog 10000000 <in/unif_rand/10000000.txt

runAll: run_nearly_sorted_100k run_nearly_sorted_1M run_nearly_sorted_10M run_reverse_sorted_100k run_reverse_sorted_1M run_reverse_sorted_10M run_sorted_100k run_sorted_1M run_sorted_10M run_unif_rand_100k run_unif_rand_1M run_unif_rand_10M

runAll_100k: run_nearly_sorted_100k run_reverse_sorted_100k run_sorted_100k run_unif_rand_100k

clean:
	@rm -f *.o
	@rm -f prog