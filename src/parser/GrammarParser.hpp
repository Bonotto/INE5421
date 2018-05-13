#include <iostream>
#include <boost/spirit/home/x3.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/fusion/include/io.hpp>

namespace ast {
struct Production
{
    std::string m_production;
};

struct Line
{
    std::string m_symbol;
    std::vector<Production> m_productions;
};

struct Document
{
    std::vector<Line> m_lines;
};
}

BOOST_FUSION_ADAPT_STRUCT(ast::Production, m_production)
BOOST_FUSION_ADAPT_STRUCT(ast::Line, m_symbol, m_productions)
BOOST_FUSION_ADAPT_STRUCT(ast::Document, m_lines)

namespace parser {
    namespace x3    = boost::spirit::x3;
    namespace ascii = x3::ascii;

    x3::rule<class production_, ast::Production> production{"production"};
    x3::rule<class line_, ast::Line>             line{"line"};
    x3::rule<class document_, ast::Document>     document{"document"};

    const auto identifier     = x3::lexeme[+x3::char_("a-zA-Z")];
    const auto production_def = identifier;
    const auto line_def       = identifier >> x3::lit("->") >> production % "|";
    const auto document_def   = +line % "\n";

    BOOST_SPIRIT_DEFINE(production, line, document);
}
