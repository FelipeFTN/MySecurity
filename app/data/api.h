#ifndef _API_H_
#define _API_H_

// API struct
struct api_data_struct {
  bool handshake;
};

// API save data
int save_api_data(struct api_data_struct data);

// API get data
struct api_data_struct get_api_data();

#endif
