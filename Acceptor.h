#include <memory>
#include <functional>
#include "Channel.h"

namespace yuan {

class CEventLoop;

class CAcceptor
{
public:
    using ptr = std::shared_ptr<CAcceptor>;
    using ConnectCB = std::function<void(ISocket::ptr)>;

    CAcceptor(CEventLoop* pEventLoop, const std::string& strIp, std::int32_t nPort);
    ~CAcceptor();

    void OnConnection();
    void SetConnectCB(ConnectCB funcCB);

private:
    CEventLoop* m_pEventLoop;
    ISocket::ptr m_pSocket;
    CChannel::ptr m_pChannel;
    ConnectCB m_cbConnect;
};

}