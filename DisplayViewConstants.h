#pragma once

namespace DisplayViewConstants
{
    static constexpr int scene_x_origin_ = 0;
    static constexpr int scene_y_origin_ = 0;
    static constexpr int scene_width_ = 1000;
    static constexpr int scene_heigh_ = 1000;
    static constexpr int scene_x_middle_ = scene_x_origin_ + scene_width_ / 2;
    static constexpr int scene_y_middle_ = scene_y_origin_ + scene_heigh_ / 2;

    static constexpr int minimum_corridor_width_ = 100;
    static constexpr int default_corridor_width_ = 300;
    static constexpr int maximum_corridor_width = 1000;

    static constexpr int corridor_height_ = 50;
    static constexpr int corridor_x_origin_ = 10;
    static constexpr int corridor_y_origin_ = scene_y_middle_ - corridor_height_ / 2;

    static constexpr int flat_width_ = 50;
    static constexpr int flat_height_ = 50;
    static constexpr int separation_between_flats_ = 5;
    static constexpr int separation_between_flats_and_corridor_ = 5;
    static constexpr int upper_flats_y_origin_ = corridor_y_origin_ - flat_height_ - separation_between_flats_and_corridor_;
    static constexpr int lower_flats_y_origin_ = corridor_y_origin_ + corridor_height_ + separation_between_flats_and_corridor_;
}
