/*
** EPITECH PROJECT, 2024
** Day07AM
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

namespace WarpSystem {
    class QuantumReactor {
    private:
        bool _stability ;
    public:
        QuantumReactor(/* args */);
        ~QuantumReactor();

        bool isStable();
        void setStability(bool stability) ;
    };

    class Core {
        private:
            QuantumReactor *_coreReactor;
        public:
            Core( QuantumReactor *coreReactor);
            ~Core();

            QuantumReactor *checkReactor();
    };
}

#endif /* !WARPSYSTEM_HPP_ */
