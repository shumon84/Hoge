double average(double array[], uint32_t element_number);
double average(double array[], uint32_t element_number){
  uint32_t i;
  double sum = 0;
  for(i = 0; i < element_number; i++)
    sum += array[i];
  return sum / element_number;
}
