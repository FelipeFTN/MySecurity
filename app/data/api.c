#include <stdbool.h>

#include "api.h"

// API struct
struct api_data_struct api_data = {
  false
};

// API save data
int save_api_data(struct api_data_struct data) { 
  api_data = data;
  return 0;
}

// API get data
struct api_data_struct get_api_data() {
  return api_data; 
}
