

struct subvector {
    int *mas;
    unsigned int top;
    unsigned int capacity;
};

bool init(subvector *qv){ //инициализация пустого недовектора
    (*qv).mas = NULL;
    (*qv).capacity = 0;
    (*qv).top = 0;
    return 1;
};


bool resize(subvector *qv, unsigned int new_capacity){ //увеличить емкость недовектора
    int *new_mas = new int[new_capacity];
    for (int i = 0; i < (*qv).top; i ++){
        new_mas[i] = (*qv).mas[i];
    }
    (*qv).capacity = new_capacity;
    (*qv).mas = new_mas;
    return 1;
};

bool push_back(subvector *qv, int d){ //добавление элемента в конец недовектора с выделением дополнительной памяти при необходимости
    if ((*qv).capacity == (*qv).top){
        resize(qv, (*qv).capacity + 1);
    }
    (*qv).mas[(*qv).top + 1] = d;
    (*qv).top += 1;
    return 1;
};

void shrink_to_fit(subvector *qv){ //очистить неиспользуемую память
    int *new_mas = new int[(*qv).top];
    for (int i = (*qv).top; i < (*qv).capacity; i ++){
        delete &(*qv).mas[i];
    }
    (*qv).capacity = (*qv).top;
    (*qv).mas = new_mas;
    return;
};

int pop_back(subvector *qv){ //удаление элемента с конца недовектора
    shrink_to_fit(qv);
    int d = (*qv).mas[(*qv).top];
    delete &(*qv).mas[(*qv).top];
    (*qv).capacity -= 1;
    (*qv).top -= 1;
    return d;
};

void clear(subvector *qv){ //очистить содержимое недовектора, занимаемое место при этом не меняется
    (*qv).top = 0;
    return;
};

void destructor(subvector *qv){ //очистить всю используемую память, инициализировать недовектор как пустой
    for (int i = 0; i < (*qv).top; i++)
        delete[] &(*qv).mas[i];
    init(qv);
    return;
};

