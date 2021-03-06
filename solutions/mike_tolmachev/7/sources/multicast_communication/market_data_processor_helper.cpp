#include "market_data_processor_helper.h"


namespace multicast_communication
{

market_data_processor_helper::market_data_processor_helper(std::ofstream& output) : output_(output)
{
}

market_data_processor_helper::~market_data_processor_helper()
{
}

void market_data_processor_helper::new_trade( const trade_message_ptr& msg)
{
	boost::mutex::scoped_lock lock(mtx);
	
	output_ << std::fixed << "T" << " "
		<< msg->security_symbol() << " "
		<< std::setprecision(2) << msg->price() << " "
		<< std::setprecision(1) << msg->volume() << std::endl;
}

void market_data_processor_helper::new_quote( const quote_message_ptr& msg)
{
	boost::mutex::scoped_lock lock(mtx);

	output_ << std::fixed << "Q" << " "
		<< msg->security_symbol() << " "
		<< std::setprecision(2) << msg->bid_price() << " "
		<< std::setprecision(1) << msg->bid_volume() << " "
		<< std::setprecision(2) << msg->offer_price() << " "
		<< std::setprecision(1) << msg->offer_volume() << std::endl;
}

}