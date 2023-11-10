#ifndef KORTHAND_H
#define KORTHAND_H
#include <vector>
#include <kort.h>

class Korthand
{
public:
    Korthand();
    void rensa ();
    int antalkort() const;
    Kort kort(int nr) const;
    void stoppaInkort(const Kort &kort);
    int poang() const;
private:
    std::vector<Kort> m_Korten;
};

#endif // KORTHAND_H
