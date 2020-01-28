#ifndef SERVICES_H
#define SERVICES_H

/*
 * uid - to match with the sqlite services uid
 */
struct services_info
{
    int uid;
};

struct services_info service[] =
{
    {1000},
    {1001}
};

#endif
