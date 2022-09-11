#include "client.h"

client::client( const client_id& id, std::unique_ptr<net::session> session, std::shared_ptr<io::io_iface> io )
     : id_ { id }
     , session_ { std::move( session ) }
     , io_ { io }
     , reader_ {}
     , writer_ {}
{
     session_->run();
}

client::~client()
{
     session_->stop();
}

void client::send_message( const std::string& message )
{
     io_->put( message );
}

std::string client::prepare_message( const std::string& message ) const
{
     return id_ + " | " + message;
}