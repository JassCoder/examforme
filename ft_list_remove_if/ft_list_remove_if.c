while (curr)
{
    if (cmp(curr->data, data_ref) == 0) // match → delete
    {
        tmp = curr;
        if (prev == NULL) // deleting head
            *begin_list = curr->next;
        else
            prev->next = curr->next; // bypass node
        curr = curr->next;
        free(tmp);
    }
    else // no match → keep, advance prev
    {
        prev = curr;
        curr = curr->next;
    }
}