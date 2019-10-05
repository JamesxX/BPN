#ifndef NEURALNETWORK_PUBLIC_LAYER_HPP
#define NEURALNETWORK_PUBLIC_LAYER_HPP

#include <NeuralNetwork/public/library.hpp>
#include <NeuralNetwork/public/forwardDeclaration.hpp>

#include <NeuralNetwork/public/neuron.hpp>
#include <vector>

namespace NeuralNetwork_ns
{

	namespace Layer
	{

		class ILayer
		{
		public:

		private:
			NeuralNetwork_ns::neuron_list_t m_Neurons;
		};

		class InputLayer : public ILayer
		{

		};

		class HiddenLayer : public ILayer
		{

		};

		class OutputLayer : public ILayer
		{

		};

	}

}

#endif // NEURALNETWORK_PUBLIC_LAYER_HPP