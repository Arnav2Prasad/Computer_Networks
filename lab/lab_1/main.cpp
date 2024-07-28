#include <cmath>
#include <iostream>
using namespace std;
#include <vector>
#include <string>

// IP address is of the form a.b.c.d/x

// to check for valid subnet mask (user-input)
int valid_subnet_mask(string s){
	if (s[0] != '/'){
		return 0;
	}
	int int_subnet_mask = stoi(s.substr(1));
	if (int_subnet_mask >= 0 && int_subnet_mask <= 32){
		return 1;
	}
	return 0;
}

int check_for_valid_ip_address(string s){
	int tmp=0;
	string str="";
	for (int i=0;i<s.length();i++){
		if (s[i] == '.'){
			tmp = stoi(str);
			str="";
			if (tmp>255 || tmp<0){
				cout << "invalid IP address" << endl;
				return 0;
			}
		}
		else{
			str += s[i];
		}
	}
	// check for 'd' part
	tmp = stoi(str);
	
	if (tmp>255 || tmp<0){
		cout << "invalid IP address" << endl;
		return 0;
	}

	cout << "Valid IP address" << endl;
	return 1;
}
	
int get_start_ip_address(int* start_ip_address_a ,int* start_ip_address_b ,int* start_ip_address_c ,int* start_ip_address_d ,int network_id_a ,int network_id_b ,int network_id_c ,int network_id_d ,int broadcast_id_a ,int broadcast_id_b ,int broadcast_id_c ,int broadcast_id_d ){
	if ( network_id_a == broadcast_id_a && network_id_b == broadcast_id_b &&  network_id_c == broadcast_id_c &&  network_id_d == broadcast_id_d){
		cout << "There is no IP starting address, So NO device can be added for the given rnge of IP address" << endl;
		return -1;
	}

	cout << "(Inside function) Network ID : " << network_id_a << "." <<  network_id_b << "." << network_id_c  << "." << network_id_d << endl;
	*start_ip_address_d = (network_id_d + 1)%256;
	if (network_id_d + 1 > 255){
		cout << "58" << endl;
		*start_ip_address_c = (network_id_c + 1)%256;
		if (network_id_c + 1 > 255){
			cout << "61" << endl;
			*start_ip_address_b =( network_id_b + 1)%256;
			if (network_id_b + 1 > 255){
				cout << "64" << endl;
				if (network_id_a + 1 > 255){
					cout << "66" << endl;
					cout << "Cant allocate starting IP address for any device" << endl;
					return -1;
				}
				*start_ip_address_a = network_id_a + 1;
			}
			else{
				*start_ip_address_a = network_id_a;
			}
			
		}
		else{
			*start_ip_address_b = network_id_b;
			*start_ip_address_a = network_id_a;
		
		}
	}
	else{
		*start_ip_address_c = network_id_c;
		*start_ip_address_b = network_id_b;
		*start_ip_address_a = network_id_a;
	}
	
	if ( *start_ip_address_a == broadcast_id_a && *start_ip_address_b == broadcast_id_b &&  *start_ip_address_c == broadcast_id_c &&  *start_ip_address_d == broadcast_id_d){
		cout << "There is no IP starting address, So NO device can be added for the given rnge of IP address" << endl;
		return -1;
	}

	return 1;

}
	
int get_end_ip_address(int* end_ip_address_a ,int* end_ip_address_b ,int* end_ip_address_c ,int* end_ip_address_d ,int network_id_a ,int network_id_b ,int network_id_c ,int network_id_d ,int broadcast_id_a ,int broadcast_id_b ,int broadcast_id_c ,int broadcast_id_d ){
	if ( network_id_a == broadcast_id_a && network_id_b == broadcast_id_b &&  network_id_c == broadcast_id_c &&  network_id_d == broadcast_id_d){
		cout << "There is no IP ending address, So NO device can be added for the given rnge of IP address" << endl;
		return -1;
	}

	cout << "(Inside function ending address) Network ID : " << network_id_a << "." <<  network_id_b << "." << network_id_c  << "." << network_id_d << endl;

	if (broadcast_id_d > 1){
		cout << "107" << endl;
		*end_ip_address_d = network_id_d-1;
		*end_ip_address_c = network_id_c;
		*end_ip_address_b = network_id_b;
		*end_ip_address_a = network_id_a;
	}
	else{
		*end_ip_address_d = network_id_d-1 + 255;
		if (broadcast_id_c > 1){
			*end_ip_address_c = network_id_c -1;
			*end_ip_address_b = network_id_b;
			*end_ip_address_a = network_id_a;
		}
	
		
		else{
			*end_ip_address_c = network_id_c -1+255;
			if (broadcast_id_b > 1){
				*end_ip_address_b = network_id_b -1;
				*end_ip_address_a = network_id_a;
			}
			
			else{
				*end_ip_address_b = network_id_b -1 + 255;
				if (broadcast_id_a > 1){
					*end_ip_address_a = network_id_a-1;
				}
				else{
					cout << "There is NO ending address" << endl;
					return -1;
				}

			}
	
		}
	}
	
	cout << "(Inside function ending address) Ending Address : " << *end_ip_address_a << "." << *end_ip_address_b << "." << *end_ip_address_c  << "." << *end_ip_address_a << endl;

	if ( *end_ip_address_a == network_id_a && *end_ip_address_b == network_id_b &&  *end_ip_address_c == network_id_c &&  *end_ip_address_d == network_id_d){
		cout << "There is no IP ending address, So NO device can be added for the given rnge of IP address" << endl;
		return -1;
	}

	return 1;

}


// Function to convert a binary string to a decimal integer
int binary_to_decimal(const string& binary) {
    int decimal = 0;
    int base = 1; // 2^0

    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base = base * 2;
    }

    return decimal;
}


void find_str_to_int(const string& st, int* a, int* b, int* c, int* d) {
    int a1 = binary_to_decimal(st.substr(0, 8));
    int b1 = binary_to_decimal(st.substr(8, 8));
    int c1 = binary_to_decimal(st.substr(16, 8));
    int d1 = binary_to_decimal(st.substr(24, 8));

    *a = a1;
    *b = b1;
    *c = c1;
    *d = d1;

}


void extract_ip_address(string ip_address ,int* ip_address_a ,int* ip_address_b ,int* ip_address_c ,int* ip_address_d){
	int len = ip_address.length();
	int step=0;
	string str="";
	for (int i=0;i<len;i++){
		if (ip_address[i] == '.'){
			cout << "stoi(str) : " << stoi(str) << endl;
			if (step==0){
				*ip_address_a = stoi(str);
				step++;
				str="";
			}else if (step==1){
				*ip_address_b = stoi(str);
				step++;
				str="";
			}else if (step==2){
				*ip_address_c = stoi(str);
				step++;
				str="";
			}
			else if (step==3){
				*ip_address_d = stoi(str);
				step++;
				str="";
			}


		}
		else{
			str +=ip_address[i];
		}
	}
	if (step==3){
		*ip_address_d = stoi(str);
		step++;
	}

}



void calculate_subnet_mask_abcdx(string s , int& a , int& b , int& c , int& d){
	string tmp = s.substr(1);
	int int_subnet_mask = stoi(tmp);

	int left_len = int_subnet_mask;
	int len = 32;
	string st(len, '0'); // Initialize a string of size 32 with '0'

	for (int i=0;i<left_len ; i++){
		st[i]='1';
	}
	
	find_str_to_int(st , &a , &b , &c , &d);
}


void find_network_id(int* network_id_a ,int* network_id_b ,int* network_id_c ,int* network_id_d ,int subnet_mask_a,int subnet_mask_b,int subnet_mask_c,int subnet_mask_d ,int ip_address_a ,int ip_address_b ,int ip_address_c ,int ip_address_d){

	// Print the subnet mask and IP address values
    	cout << "Subnet Mask: " << subnet_mask_a << "." << subnet_mask_b << "." << subnet_mask_c << "." << subnet_mask_d << endl;
    	cout << "IP Address: " << ip_address_a << "." << ip_address_b << "." << ip_address_c << "." << ip_address_d << endl;


	 *network_id_a = subnet_mask_a & ip_address_a;
	 *network_id_b = subnet_mask_b & ip_address_b;
	 *network_id_c = subnet_mask_c & ip_address_c;
	 *network_id_d = subnet_mask_d & ip_address_d;

}

void find_broadcast_address(int* broadcast_id_a ,int* broadcast_id_b ,int* broadcast_id_c ,int* broadcast_id_d ,int subnet_mask_a,int subnet_mask_b,int subnet_mask_c,int subnet_mask_d ,int ip_address_a ,int ip_address_b ,int ip_address_c ,int ip_address_d){
	
	// Perform bitwise NOT operation on subnet masks and ensure proper masking
    	int subnet_mask_a_not = ~subnet_mask_a & 0xFF;
   	int subnet_mask_b_not = ~subnet_mask_b & 0xFF;
    	int subnet_mask_c_not = ~subnet_mask_c & 0xFF;
    	int subnet_mask_d_not = ~subnet_mask_d & 0xFF;

	*broadcast_id_a = subnet_mask_a_not | ip_address_a;
	*broadcast_id_b = subnet_mask_b_not | ip_address_b;
	*broadcast_id_c = subnet_mask_c_not | ip_address_c;
	*broadcast_id_d = subnet_mask_d_not | ip_address_d;
}

int main(){
	cout << "Enter subnet mask : ";
	string subnet_mask;
	cin >> subnet_mask;
	cout << "--------" << endl;
	
	if (valid_subnet_mask(subnet_mask) == 0){
		cout << "incorrect subnet mask input, code execution stopped" << endl;
		return 0;
	}
	
	cout << "correct subnet mask input" << endl;
	
	int subnet_mask_a=1;
	int subnet_mask_b=1;
	int subnet_mask_c=1;
	int subnet_mask_d=1;

	calculate_subnet_mask_abcdx(subnet_mask, subnet_mask_a,subnet_mask_b,subnet_mask_c,subnet_mask_d);

	cout << "Subnet Mask : " << subnet_mask_a << "." <<  subnet_mask_b  << "." <<  subnet_mask_c  << "." <<  subnet_mask_d  << endl;

	string ip_address;
	cout << "Enter IP address : ";
	cin >> ip_address;
	cout << "IP address is : " << ip_address << endl;
	
	cout << check_for_valid_ip_address(ip_address) << endl;
	if (check_for_valid_ip_address(ip_address) == 0){
		cout << "Invalid input IP address" << endl;
		return 0;
	}

	int ip_address_a = 1;
	int ip_address_b = 1;
	int ip_address_c = 1;
	int ip_address_d = 1;

	extract_ip_address(ip_address , &ip_address_a , &ip_address_b ,&ip_address_c , &ip_address_d);
	cout << "valid input IP address" << endl;

	cout << "IP Address : " << ip_address_a << "." <<  ip_address_b<< "." << ip_address_c  << "." << ip_address_d << endl;
	
	int network_id_a = 1;
	int network_id_b = 1;
	int network_id_c = 1;
	int network_id_d = 1;

	find_network_id(&network_id_a , &network_id_b ,&network_id_c ,&network_id_d ,subnet_mask_a,subnet_mask_b,subnet_mask_c,subnet_mask_d , ip_address_a ,ip_address_b ,ip_address_c ,ip_address_d);

	cout << "Network ID : " << network_id_a << "." <<  network_id_b << "." << network_id_c  << "." << network_id_d << endl;


	int broadcast_id_a = 1;
	int broadcast_id_b = 1;
	int broadcast_id_c = 1;
	int broadcast_id_d = 1;

	find_broadcast_address(&broadcast_id_a , &broadcast_id_b ,&broadcast_id_c ,&broadcast_id_d ,subnet_mask_a,subnet_mask_b,subnet_mask_c,subnet_mask_d , ip_address_a ,ip_address_b ,ip_address_c ,ip_address_d);

        cout << "Broadcast Address : " << broadcast_id_a << "." <<  broadcast_id_b << "." << broadcast_id_c  << "." << broadcast_id_d << endl;

	int start_ip_address_a = -1;
	int start_ip_address_b = -1;
	int start_ip_address_c = -1;
	int start_ip_address_d = -1;

	if (get_start_ip_address(&start_ip_address_a , &start_ip_address_b , &start_ip_address_c , &start_ip_address_d , network_id_a , network_id_b , network_id_c , network_id_d ,broadcast_id_a , broadcast_id_b , broadcast_id_c , broadcast_id_d )==-1){
		cout << "Failed to calculated starting IP address" << endl;
		return 0;
	}
	
	cout << "Starting Address : " << start_ip_address_a << "." << start_ip_address_b << "." << start_ip_address_c << "." << start_ip_address_d << endl;


	int end_ip_address_a = 1;
	int end_ip_address_b = 1;
	int end_ip_address_c = 1;
	int end_ip_address_d = 1;

	if (get_end_ip_address(&end_ip_address_a , &end_ip_address_b , &end_ip_address_c , &end_ip_address_d , network_id_a , network_id_b , network_id_c , network_id_d ,broadcast_id_a , broadcast_id_b , broadcast_id_c , broadcast_id_d )==-1){
		cout << "Failed to calculated Ending IP address" << endl;
		return 0;
	}
	
	cout << "Ending Address : " << end_ip_address_a << "." << end_ip_address_b << "." << end_ip_address_c  << "." << end_ip_address_a << endl;
	cout << "code ended" << endl;
	return 0;
}

