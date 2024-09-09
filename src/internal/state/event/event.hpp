#pragma once

#include <deque>

/**
 * Represents event state holder.
 */
class EventState {
public:
    /**
     * Represents all the available application event types.
     */
    enum Type {
        /**
         * Represents resize event type, pushed by system signal. Resize signal is also thrown during application
         * startup.
         */
        RESIZE,
    };

    /**
     * Adds new event to the events queue, if predefined events queue conditions are passed.
     *
     * @param value - given event type.
     * @return result of the execution.
     */
    int addEvent(Type value);

    /**
     * Retrieves application events queue.
     *
     * @return retrieved application events queue.
     */
    std::deque<Type>* getEvents();
private:
    /**
     * Represents a queue of application events.
     */
    std::deque<Type> events;
};