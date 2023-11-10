#include "kort.h"
#include <string>
//Kort::Kort(Farg farg, int valor)
//{
//  m_farg = farg;
//  m_valor = valor;
//}

Kort::Farg Kort::farg() const
{
    return m_farg;
}

int Kort::valor() const
{
    return m_valor;
}

std::string Kort::text() const
{
    static const char* valornamn[14]{"finnsej","ess","två","tre","fyra","fem","sex","sju","åtta","nio","tio","knekt","dam","kung"};
    return fargstrang() + " " +valornamn[m_valor];
}

std::string Kort::fargstrang() const
{
    ////ruter,hjater,spader
  if(m_farg == klover)
      return "klover";
  else if(m_farg == ruter)
      return "ruter";
  else if (m_farg == hjater)
      return "hjater";
  else return "spader";

}

Kort::Kort(Kort::Farg farg, int valor) : m_farg(farg),
    m_valor(valor)
{}
