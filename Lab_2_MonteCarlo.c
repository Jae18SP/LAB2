/* REF
**http://dudevictor.github.io/projects/programacao-concorrente/shared-memory-with-openmp/ 
*/
   
   
   int main(int argc, char* argv[]) {
   long int number_tosses, number_in_circle;
   int thread_count, i;
   double x, y, distance;

   if (argc != 3) Usage(argv[0]);
   thread_count = strtol(argv[1], NULL, 10);
   number_tosses = strtoll(argv[2], NULL, 10);
   if (thread_count < 1 || number_tosses < 1) Usage(argv[0]);

   number_in_circle =0;
   srandom(0);
#  pragma omp parallel for num_threads(thread_count) \
      reduction(+: number_in_circle) private(x, y, distancia)
   for (i = 0; i < number_tosses; i++) {
      x = (double)rand()/RAND_MAX;
        y = (double)rand()/RAND_MAX;
      distance = x*x + y*y;

      if (distance <= 1) {
         number_in_circle += 1;
      }
   }
   double pi = 4*number_in_circle/((double) number_tosses);
   printf("estimate of pi = %.14f\n", pi);
   return 0;
}  /* main */
