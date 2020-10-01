import speedtest

def speed_test():
    st = speedtest.Speedtest()
    st.get_servers()
    st.get_best_server()
    st.download()
    st.upload()
    result = st.results.dict()
    return result["download"], result["upload"]


def main():
    for i in range(1):
        ds, us = speed_test()
        print('Download Speed: {:.2f} Kb/s\n'.format(ds / 1024))
        print('Upload Speed: {:.2f} Kb/s\n'.format(us / 1024))


if __name__ == '__main__':
    main()