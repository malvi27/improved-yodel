node* middle(node *head)
{
    node *fast=head, *slow =head;
    while (fast !=NULL and fast->next !=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}