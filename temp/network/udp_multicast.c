#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>     
#include <errno.h>
#include <linux/ip.h>
#include <string.h>
#include <stdlib.h>
#define MULTICAST_IP			"224.0.0.1"
#define PORT				12345
    
struct sockaddr_in server_address;
int fd_socket;

int init_connection_client( void ) {
	int sock, opt;

	errno = 0;
	//create a socket
	sock = socket( PF_INET, SOCK_DGRAM, 0 );
	if( sock == -1 ) {
		printf("%s:%u socket() error (%s), error-code: %d\n", __FILE__, __LINE__, strerror(errno), sock);
		exit(EXIT_FAILURE);
	}
	server_address.sin_family = PF_INET;
	server_address.sin_addr.s_addr = inet_addr( MULTICAST_IP );
	server_address.sin_port = htons( PORT );

	if( bind( sock, (struct sockaddr*)&server_address, sizeof(struct sockaddr)) == -1 ) {
		printf("%s:%u bind error (%s), error-code: %d\n", __FILE__, __LINE__, strerror(errno), errno);
		exit(EXIT_FAILURE);
	}
	//set socket options
	//IPTOS = type of service and precedence
	//IPTOS_LOWDELAY = minimize delay
	//IPTOS_PREC_PRIORITY = 
	opt = IPTOS_PREC_PRIORITY | IPTOS_LOWDELAY;
	if( setsockopt( sock, IPPROTO_IP, IP_TOS, &opt, sizeof(opt)) == -1 ) {
		printf("%s:%u setsockopt(IP_TOS) error (%s), error-code: %d\n", __FILE__, __LINE__, strerror(errno), errno);
		exit(EXIT_FAILURE);
	}
	//give these packets the maximum priority
	//SOL_SOCKET = manipulate at socket level
	opt = 7;
	if( setsockopt( sock, SOL_SOCKET, SO_PRIORITY, &opt, sizeof(opt)) == -1 ) {
		printf("%s:%u setsockopt(SO_PRIORITY) error (%s), error-code: %d\n", __FILE__, __LINE__, strerror(errno), errno);
		exit(EXIT_FAILURE);
	}

	return sock;
}
int send_data( unsigned char *network_data, size_t len ) {
	/* should handle EAGAIN if using  MSG_DONTWAIT*/
	if( sendto( fd_socket, network_data, len, MSG_DONTWAIT, \
		(struct sockaddr*)&server_address, sizeof(struct sockaddr_in) ) == -1 ) {
			printf("%s:%u sendto() error (%s), error-code: %d\n", __FILE__, __LINE__, strerror(errno), errno);
			return errno;
	}

	return 0;
}

int main(int argc, char **argv) {
  unsigned char *data_for_transmission;
  int sleeper=atoi(argv[1]);
  printf("%d\n",sleeper);
  data_for_transmission = malloc( 1068 );
  fd_socket=init_connection_client();
  while(1) {
	send_data( data_for_transmission, 1068 ); 
	usleep(sleeper);
  }
 return 0;
}