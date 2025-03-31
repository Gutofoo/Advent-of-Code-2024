#ifndef _ROCK_HH_
#define _ROCK_HH_

class Rock {

  public:
    Rock(unsigned long long engraving);
    Rock(const Rock& other); // deep copy constructor
    void Blink();
    void Print();
    void Insert(unsigned long long engraving);
    unsigned long Count();
    static void Prune(Rock* head);

  private:
    Rock(unsigned long long engraving, Rock* next);
    Rock(unsigned long long engraving, unsigned long multiplicity, Rock* next);
    static unsigned long Prune(unsigned long long engraving_to_find, Rock* under_evaluation, Rock* previous);
    int NumberOfDigits();
    unsigned long long engraving_ = 0U;
    unsigned long multiplicity_ = 1UL;
    Rock* next_ = nullptr;

};

#endif