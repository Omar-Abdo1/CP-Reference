// to generate number with equal probality  (تقريبا)

    std::default_random_engine generator;

     std::uniform_int_distribution<int> distribution(0,10);

     for (int i=0; i<10; ++i) {
    int number = distribution(generator);
      cout<<number<<"\n";
    }
