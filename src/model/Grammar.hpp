#ifndef MODEL_GRAMMAR_REGULAR_HPP
#define MODEL_GRAMMAR_REGULAR_HPP

#include <unordered_set>
#include <unordered_map>
#include "./GrammarComponents.hpp"


namespace formal_device
{
namespace grammar
{

class Regular
{
    template <class T>
    using set_type            = std::unordered_set<T, Hasher>;
    template <class Key, class Value>
    using map_type            = std::unordered_map<Key, Value, Hasher>;

    using symbol_type         = Symbol;
    using production_type_ptr = std::shared_ptr<Production>;

    using vocabulary_set_type = set_type<symbol_type>;
    using production_map_type = map_type<symbol_type, set_type<production_type_ptr>>;

    // Class constructors
    Regular() = delete;

    Regular(const Regular &) = default;
    Regular &operator=(const Regular &) = default;

    Regular(Regular &&) = default;
    Regular &operator=(Regular &&) = default;

    template <class Arg1, class Arg2, class Arg3, class Arg4>
    Regular(Arg1 &&vn, Arg2 &&vt, Arg3 &&productions, Arg4 &&initial_symbol) :
        m_vn{std::forward<Arg1>(vn)},
        m_vt{std::forward<Arg2>(vt)},
        m_productions{std::forward<Arg3>(productions)},
        m_initial_symbol{std::forward<Arg4>(initial_symbol)}
    {
    }

  private:
    vocabulary_set_type m_vn;
    vocabulary_set_type m_vt;
    production_map_type m_productions;
    symbol_type         m_initial_symbol;
};

}   // namespace grammar
}   // namespace formal_device

#endif // MODEL_GRAMMAR_REGULAR_HPP