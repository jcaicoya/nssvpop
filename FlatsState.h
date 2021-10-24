#pragma once


class DisplayView;
class FlatItem;


class FlatsState
{
friend class DisplayView;
friend class FlatItem;

private:
    static bool distribution_is_optimal_;
};
