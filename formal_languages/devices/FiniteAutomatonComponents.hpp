#ifndef DEVICES_FINITEAUTOMATON_COMPONENTS_H
#define DEVICES_FINITEAUTOMATON_COMPONENTS_H

#include <string>
#include <utility>
#include <unordered_set>
#include <unordered_map>

namespace formal_device
{
namespace finite_automaton
{

class Symbol
{
public:
    friend class Hasher;
    using string_type = std::string;

    Symbol() = default;

    Symbol(const Symbol &) = default;
    Symbol &operator=(const Symbol &) = default;
    Symbol(Symbol &&) = default;
    Symbol &operator=(Symbol &&) = default;

    Symbol(const string_type &symbol);
    Symbol(string_type &&symbol);

    ~Symbol() = default;

    bool operator==(const Symbol &symbol) const;
    bool operator==(const string_type &symbol) const;

private:
    string_type m_symbol{"&"};
};

class State
{
public:
    friend class Hasher;
    using string_type = std::string;

    State() = default;

    State(const State &) = default;
    State &operator=(const State &) = default;
    State(State &&) = default;
    State &operator=(State &&) = default;

    State(const string_type &state);
    State(string_type &&state);

    ~State() = default;

    bool operator==(const State &state) const;
    bool operator==(const string_type &state) const;

    State operator+(const State &sufix) const;
    State operator+(const string_type &sufix) const;

private:
    string_type m_state{"Error"}; // error
};

class Hasher
{
public:
  using symbol_type = Symbol;
  using state_type  = State;

  std::size_t operator()(const symbol_type &symbol) const;
  std::size_t operator()(const state_type &state) const;
};

} // namespace finite_automaton
} // namespace formal_device

#endif // DEVICES_FINITEAUTOMATON_COMPONENTS_H
