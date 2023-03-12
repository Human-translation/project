#include <iostream>
#include "ftp.h"

int main()
{
    FTPClient CFTPClinet;
    
    int fd = CFTPClinet.ftp_connect("152.136.112.114", 21, "work", "Li029031!!");
    if (fd < 0)
    {
        std::cout << "ftp connect falied" << std::endl;
    }

    int ret = CFTPClinet.ftp_cwd(fd, "workroot/ftp");
    std::cout << ret << std::endl;

    ret = CFTPClinet.ftp_mkd(fd, "ccc");
    std::cout << ret << std::endl;

    //下载
    unsigned long long size = 0;
    ret = CFTPClinet.ftp_retrfile(fd, "test", "ccc/test", &size, NULL);
    std::cout << ret << " " << size << std::endl;
    
    //上传
    ret = CFTPClinet.ftp_storfile(fd, "test", "ccc/test", &size, NULL);
    std::cout << ret << " " << size << std::endl;

    return 0;
}
