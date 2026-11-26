typedef struct s_list t_list;

struct s_list
{
    int data;
    t_list *next;
};

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
    t_list *sorted = 0;
    t_list *curr;
    t_list *next;
    t_list *prev;

    while (lst)
    {
        next = lst->next;
        curr = lst;
        curr->next = 0;

        if (sorted == 0 || !cmp(sorted->data, curr->data))
        {
            curr->next = sorted;
            sorted = curr;
        }
        else
        {
            prev = sorted;
            while (prev->next && cmp(prev->next->data, curr->data))
                prev = prev->next;
            curr->next = prev->next;
            prev->next = curr;
        }
        lst = next;
    }
    return sorted;
}