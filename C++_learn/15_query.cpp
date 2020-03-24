/*************************************************************************
	> File Name: 15_query.cpp
	> Author:jieni 
	> Mail: 
	> Created Time: 2020年03月24日 星期二 23时21分07秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Query_base {
    friend class Query;
    protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;
private:
    virtual QueryResult eval(const TextQuery &) const = 0;
    virtual string rep() const = 0;
};

class Query {
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);
public:
    Query(const string &);

}
