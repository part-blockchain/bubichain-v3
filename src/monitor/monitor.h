#ifndef MONITOR_H_
#define MONITOR_H_

#include <proto/cpp/monitor.pb.h>
#include <proto/cpp/overlay.pb.h>
#include <common/network.h>

namespace bubi {
	typedef std::shared_ptr<protocol::WsMessage> WsMessagePointer;

	class Monitor : public bubi::Connection {
	private:

		bool state_changed_;
		int64_t active_time_;
		std::string session_id_;
		std::string peer_node_address_;
		//bubi ��Ϣ
		std::string bubi_version_;
		int64_t monitor_version_;
		int64_t bubi_ledger_version_;
		std::string bubi_node_address_;

	public:
		Monitor(bubi::server *server_h, bubi::client *client_h, bubi::tls_server *tls_server_h, bubi::tls_client *tls_client_h, 
			bubi::connection_hdl con, const std::string &uri, int64_t id);

		void SetSessionId(const std::string &session_id);
		void SetActiveTime(int64_t current_time);
		bool IsActive() const;
		int64_t GetActiveTime() const;

		utils::InetAddress GetRemoteAddress() const;
		std::string GetPeerNodeAddress() const;

		bool SendHello(int32_t listen_port, const std::string &node_address, std::error_code &ec);
		void SetBubiInfo(const protocol::ChainStatus &hello);
	};
}

#endif