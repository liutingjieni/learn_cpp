/*************************************************************************
	> File Name: buffer.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年10月09日 星期五 14时21分07秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

class buffer {
public:
    static const size_t k_cheap_prepend = 8;
    static const size_t k_init_size = 1024;

    //初始化buffer, buffer被两个指针划分为三个空间, prepend, readable, writable
    explicit buffer(size_t init_size = k_init_size) 
    : buffer_(k_cheap_prepend + init_size),
      read_index_(k_cheap_prepend),
      write_index_(k_cheap_prepend)
    {
        //assert()
    }

    //通过指针的差值->readable空间的大小
    size_t readable_bytes() const 
    {
        return write_index_ - read_index_;
    }

    //通过指针的差值->writable空间的大小
    size_t writable_bytes() const
    {
        return buffer_.size() - write_index_;
    }

    //通过指针的差值->prependable空间的大小
    size_t prependable_bytes() const
    {
        return read_index_;
    }

    //buffer的开始的迭代器
    char *begin()
    {
        return &*buffer_.begin();
    }

    //const版本
    const char*begin() const 
    {
        return &*buffer_.begin();
    }

    //判断writable写空间的大小与待写入的大小, 如果空间不够make_space, 够了直接追加
    void ensure_writable_bytes(size_t len)
    {
        if (writable_bytes() < len) {
            make_space(len);
        }
        assert(writable_bytes() >= len); //确保分配空间或移动空间成功, 能够放入待放的数据
    }

    //返回writable
    char *begin_write()
    {
        return begin() + write_index_;
    }

    const char *begin_write() const
    {
        return begin() + write_index_;
    }

    void has_written(size_t len)
    {
        assert(len <= writable_bytes());
        write_index_ += len;
    }


    void append(const char *data, size_t len)
    {
        ensure_writable_bytes(len);
        copy(data, data + len, begin_write());
        has_written(len);
    }

    void append(const void *data, size_t len)
    {
        append(static_cast<const char *>(data), len);
    }

    void make_space(size_t len)
    {
        if (writable_bytes() + prependable_bytes() < len + k_cheap_prepend) {
            buffer_.resize(write_index_ + len);
        }
        else {
            assert(k_cheap_prepend < read_index_);
            size_t readable = readable_bytes();
            copy(begin() + read_index_, begin() + write_index_, begin() + k_cheap_prepend);
            read_index_ = k_cheap_prepend;
            write_index_ = read_index_ + readable;
            assert(readable == readable_bytes());
        }
    }
    


private:
    vector<char> buffer_;
    size_t read_index_;
    size_t write_index_;
};
