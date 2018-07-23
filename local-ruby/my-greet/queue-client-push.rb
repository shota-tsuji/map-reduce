# producer.rb
require 'drb/drb'
#STDOUT.sync = true

def main(argv)
	if( argv.length != 2 )
		$stderr.printf("Usage: %% ruby $0 hostname port\n")
		exit( 1 )
	end
	hostname = argv[0]
	portno	 = argv[1]
	url = "druby://" + hostname + ":" + portno
	printf("url is %s\n", url)
	DRb.start_service
	#queue = DRbObject.new_with_uri('druby://localhost:9999')
	queue = DRbObject.new_with_uri(url)

	#val = gets.to_i
	val = STDIN.gets.chomp.to_i
	queue.push(val)
	queue.push(99)
	queue.push(128)
end

main(ARGV)
